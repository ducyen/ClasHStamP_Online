from enum import Enum, auto
import sys

def IsIn( leaf, composite ):
    return ( composite >= leaf and ( composite & leaf ) > 0 )

def MakeMask(bitShift, bitCount):
    return (1 << bitCount) - 1 << bitShift

class ParallelStatemachine:
    def __init__(self, _main, _stateBitShift, _parent):
        self.stateBitShift = _stateBitShift     # Should be moved to Parallel State Machine
        self.parent = _parent                   # Should be moved to Parallel State Machine
        self.lastEnteredState = 0               # Should be moved to Parallel State Machine
        self.stateCount = 0                     # Should be moved to Parallel State Machine
    def MakeState(self, stateBit):
        return 1 << (stateBit + self.stateBitShift)

class Statemachine:
    def __init__(self, _main, _stateBitShift, _parent):
        self.main = _main
        self.currentState = 0
        self.sourceState = 0
        self.lcaState = 0
        self.targetState = 0
        self.pseudoState = 0
        self.isExternalTrans = 0
        self.regionMask = 0
        self.lastEnteredStateRecovering = False
    def CommitTrans(self):
        self.currentState = self.targetState
        self.isExternalTrans = False
    def DefaultEntryAction(self, text):
        print(text + ' enter')
        self.main.lastEnteredState = self.main.lastEnteredState & ~self.regionMask | self.currentState
        #parent = self.parent
        #while parent != None:
        #    parent.lastEnteredState = parent.lastEnteredState & ~self.regionMask | self.currentState
        #    parent = parent.parent        
    def DefaultExitAction(self, text):
        print(text + ' exit')
    def Enterable(self, thisState):
        isThisLca = IsIn(self.lcaState, thisState)
        if not isThisLca or self.lcaState == 0:           
            return True
        return False
    def Exitable(self, thisState):
        isThisLca = IsIn(self.sourceState, thisState) and IsIn(self.targetState, thisState)
        if not isThisLca or self.isExternalTrans:
            self.isExternalTrans = self.isExternalTrans and not isThisLca
            return True
        else:
            self.lcaState = thisState
        return False

gCount = 0
def get_next(fix = None):
    global gCount
    if fix == None:
        curCount = gCount
    else:
        curCount = fix
    gCount = curCount + 1
    return curCount

gVar = 1

# class MainTop extends Statemachine
#   ...
#   class MainTopRgn0
#     def EventHandle(...):
#       ...
#   def __init__(self):
#     self.Substatemachine0Hsm = SharedTopFHsm(self)
#     self.S0Rgn1Hsm = _S0Rgn1Hsm(self)
#     self.Substatemachine1Hsm = SharedTopFHsm(self)
#     self.MainTopRgn0Hsm = _MainTopRgn0Hsm(self)
#   def EventHandle(...):   // replace DispatchEvent
#     ...
# 




class Events(Enum):
    E0 = auto()
    E1 = auto()
    E10 = auto()
    E11 = auto()
    E2 = auto()
    E3 = auto()
    E4 = auto()
    eLocal = auto()
# Statemachine sub-class
gCount = 0
class SharedTop(ParallelStatemachine):
    # States enumeration
    Bit_InitialPseudostate2 = get_next()
    Bit_State1 = get_next()
    Bit_State0 = get_next()
    Bit_EntryPt0 = get_next()
    Bit_ExitPoint0 = get_next()
    StateCount = get_next()
    # Region sub-class
    class _SharedStmHsm(Statemachine):
        # Region implementation: SharedStm
        def State1_Enter(self):
            if self.Enterable(self.main.State1):
                self.SharedStm_Enter()
                self.DefaultEntryAction('State1')
        # end def
        def State1_EventHandle(self, e, params):
            self.sourceState = self.main.State1
            if e == Events.E10:
                self.BgnTrans(self.main.State0)
                self.EndTrans()
                return True
            return self.SharedStm_EventHandle(e, params)
        # end def
        def State1_Exit(self):
            if self.Exitable(self.main.State1):
                self.DefaultExitAction('State1')
                self.SharedStm_Exit()
        # end def
        def State0_Enter(self):
            if self.Enterable(self.main.State0):
                self.SharedStm_Enter()
                self.DefaultEntryAction('State0')
        # end def
        def State0_EventHandle(self, e, params):
            self.sourceState = self.main.State0
            if e == Events.E11:
                self.BgnTrans(self.main.SharedStm)
                self.parent.pseudoState = self.main.ExitPoint0
                self.EndTrans()
                return True
            return self.SharedStm_EventHandle(e, params)
        # end def
        def State0_Exit(self):
            if self.Exitable(self.main.State0):
                self.DefaultExitAction('State0')
                self.SharedStm_Exit()
        # end def
        def SharedStm_Enter(self):
            if self.Enterable(self.main.SharedStm):
                if self.targetState == self.main.SharedStm:
                    self.pseudoState = self.main.InitialPseudostate2
                if self.lastEnteredStateRecovering:
                    self.pseudoState = self.main.lastEnteredState & self.main.SharedStm
                self.DefaultEntryAction('SharedStm')
        # end def
        def SharedStm_EventHandle(self, e, params):
            self.sourceState = self.main.SharedStm
            return False
        # end def
        def SharedStm_Exit(self):
            if self.Exitable(self.main.SharedStm):
                self.DefaultExitAction('SharedStm')
        # end def
        def DefaultTrans(self):
            self.sourceState = self.currentState
            self.lcaState = 0
            if self.pseudoState == self.main.InitialPseudostate2:
                self.BgnTrans(self.main.State1)
                self.EndTrans()
                return True
            elif self.pseudoState == self.main.EntryPt0:
                self.BgnTrans(self.main.State0)
                self.EndTrans()
                return True
            elif self.currentState != 0 and self.currentState != self.pseudoState:
                self.BgnTrans(self.pseudoState)
                self.EndTrans()
                return True
            self.lastEnteredStateRecovering = False
            return False
        # end def
        def BgnTrans(self, targetState):
            self.targetState = targetState
            self.pseudoState = targetState
            if self.currentState == self.main.SharedStm:
                self.SharedStm_Exit()
            elif self.currentState == self.main.State1:
                self.State1_Exit()
            elif self.currentState == self.main.State0:
                self.State0_Exit()
        # end def
        def EventHandle(self, e, params):
            if self.currentState == self.main.SharedStm:
                return self.SharedStm_EventHandle(e, params)
            elif self.currentState == self.main.State1:
                return self.State1_EventHandle(e, params)
            elif self.currentState == self.main.State0:
                return self.State0_EventHandle(e, params)
        # end def
        def EndTrans(self):
            self.currentState = self.targetState
            self.isExternalTrans = False
            if self.currentState == self.main.SharedStm:
                self.SharedStm_Enter()
            elif self.currentState == self.main.State1:
                self.State1_Enter()
            elif self.currentState == self.main.State0:
                self.State0_Enter()
        # end def
    def __init__(self, _main, _stateBitShift, _parent):
        super().__init__(_main, _stateBitShift, _parent)
        # States definitions
        self.InitialPseudostate2 = self.MakeState(SharedTop.Bit_InitialPseudostate2)
        self.State1 = self.MakeState(SharedTop.Bit_State1)
        self.State0 = self.MakeState(SharedTop.Bit_State0)
        self.EntryPt0 = self.MakeState(SharedTop.Bit_EntryPt0)
        self.ExitPoint0 = self.MakeState(SharedTop.Bit_ExitPoint0)
        self.SharedStm = self.InitialPseudostate2 | self.State1 | self.State0 | self.EntryPt0 | self.ExitPoint0
        self.stateCount = SharedTop.StateCount
        # sub-machine and regions declaration
        self.SharedStmHsm = self._SharedStmHsm(self, self.stateBitShift, self.parent)
    def EventHandle(self, e, params):
        result = False
        result = self.SharedStmHsm.EventHandle(e, params) or result
        return result
    # end def
    def DefaultTrans(self):
        while True:
            result = False
            result = self.SharedStmHsm.DefaultTrans() or result
            if result == False:
                break
        # end loop
    # end def
    def Initiate(self, lastEnteredStateRecovering, entryPoint = 0):
        if entryPoint != 0:
            self.SharedStmHsm.pseudoState = entryPoint
            return
        if self.SharedStmHsm.pseudoState == 0:
            self.SharedStmHsm.pseudoState = self.SharedStm
        self.SharedStmHsm.lastEnteredStateRecovering = lastEnteredStateRecovering
        self.SharedStmHsm.regionMask = self.SharedStm
        self.SharedStmHsm.BgnTrans(self.SharedStmHsm.pseudoState)
        self.SharedStmHsm.EndTrans()
    # end def
    def Terminate(self):
        self.SharedStmHsm.BgnTrans(0)
        self.SharedStmHsm.EndTrans()
    # end def
# Statemachine sub-class
gCount = 0
class MainTop(ParallelStatemachine):
    # States enumeration
    Bit_MainStm_Init = get_next()
    Bit_SubmachineState1 = get_next()
    Bit_SubmachineState1_SharedTop = get_next(Bit_SubmachineState1 + SharedTop.StateCount)
    Bit_S0_Init = get_next()
    Bit_S011 = get_next()
    Bit_InitialPseudostate0 = get_next()
    Bit_S012 = get_next()
    Bit_InitialPseudostate1 = get_next()
    Bit_S03 = get_next()
    Bit_S0_Rgn1_Init = get_next()
    Bit_S021 = get_next()
    Bit_InitialPseudostate2 = get_next()
    Bit_S022 = get_next()
    Bit_InitialPseudostate3 = get_next()
    Bit_S04 = get_next()
    Bit_SubmachineState0 = get_next()
    Bit_SubmachineState0_SharedTop = get_next(Bit_SubmachineState0 + SharedTop.StateCount)
    Bit_S0_Rgn2_Init = get_next()
    Bit_State2_Init = get_next()
    StateCount = get_next()
    # Region sub-class
    class _S01Rgn1Hsm(Statemachine):
        # Region implementation: S01Rgn1
        def S012_Enter(self):
            if self.Enterable(self.main.S012):
                self.S01Rgn1_Enter()
                self.DefaultEntryAction('S012')
        # end def
        def S012_EventHandle(self, e, params):
            self.sourceState = self.main.S012
            return self.S01Rgn1_EventHandle(e, params)
        # end def
        def S012_Exit(self):
            if self.Exitable(self.main.S012):
                self.DefaultExitAction('S012')
                self.S01Rgn1_Exit()
        # end def
        def S01Rgn1_Enter(self):
            if self.Enterable(self.main.S01Rgn1):
                if self.targetState == self.main.S01Rgn1:
                    self.pseudoState = self.main.InitialPseudostate1
                if self.lastEnteredStateRecovering:
                    self.pseudoState = self.main.lastEnteredState & self.main.S01Rgn1
                self.DefaultEntryAction('S01Rgn1')
        # end def
        def S01Rgn1_EventHandle(self, e, params):
            self.sourceState = self.main.S01Rgn1
            return False
        # end def
        def S01Rgn1_Exit(self):
            if self.Exitable(self.main.S01Rgn1):
                self.DefaultExitAction('S01Rgn1')
        # end def
        def DefaultTrans(self):
            self.sourceState = self.currentState
            self.lcaState = 0
            if self.pseudoState == self.main.InitialPseudostate1:
                self.BgnTrans(self.main.S012)
                self.EndTrans()
                return True
            elif self.currentState != 0 and self.currentState != self.pseudoState:
                self.BgnTrans(self.pseudoState)
                self.EndTrans()
                return True
            self.lastEnteredStateRecovering = False
            return False
        # end def
        def BgnTrans(self, targetState):
            self.targetState = targetState
            self.pseudoState = targetState
            if self.currentState == self.main.S01Rgn1:
                self.S01Rgn1_Exit()
            elif self.currentState == self.main.S012:
                self.S012_Exit()
        # end def
        def EventHandle(self, e, params):
            if self.currentState == self.main.S01Rgn1:
                return self.S01Rgn1_EventHandle(e, params)
            elif self.currentState == self.main.S012:
                return self.S012_EventHandle(e, params)
        # end def
        def EndTrans(self):
            self.currentState = self.targetState
            self.isExternalTrans = False
            if self.currentState == self.main.S01Rgn1:
                self.S01Rgn1_Enter()
            elif self.currentState == self.main.S012:
                self.S012_Enter()
        # end def
    # Region sub-class
    class _S02Rgn1Hsm(Statemachine):
        # Region implementation: S02Rgn1
        def S022_Enter(self):
            if self.Enterable(self.main.S022):
                self.S02Rgn1_Enter()
                self.DefaultEntryAction('S022')
        # end def
        def S022_EventHandle(self, e, params):
            self.sourceState = self.main.S022
            return self.S02Rgn1_EventHandle(e, params)
        # end def
        def S022_Exit(self):
            if self.Exitable(self.main.S022):
                self.DefaultExitAction('S022')
                self.S02Rgn1_Exit()
        # end def
        def S02Rgn1_Enter(self):
            if self.Enterable(self.main.S02Rgn1):
                if self.targetState == self.main.S02Rgn1:
                    self.pseudoState = self.main.InitialPseudostate3
                if self.lastEnteredStateRecovering:
                    self.pseudoState = self.main.lastEnteredState & self.main.S02Rgn1
                self.DefaultEntryAction('S02Rgn1')
        # end def
        def S02Rgn1_EventHandle(self, e, params):
            self.sourceState = self.main.S02Rgn1
            return False
        # end def
        def S02Rgn1_Exit(self):
            if self.Exitable(self.main.S02Rgn1):
                self.DefaultExitAction('S02Rgn1')
        # end def
        def DefaultTrans(self):
            self.sourceState = self.currentState
            self.lcaState = 0
            if self.pseudoState == self.main.InitialPseudostate3:
                self.BgnTrans(self.main.S022)
                self.EndTrans()
                return True
            elif self.currentState != 0 and self.currentState != self.pseudoState:
                self.BgnTrans(self.pseudoState)
                self.EndTrans()
                return True
            self.lastEnteredStateRecovering = False
            return False
        # end def
        def BgnTrans(self, targetState):
            self.targetState = targetState
            self.pseudoState = targetState
            if self.currentState == self.main.S02Rgn1:
                self.S02Rgn1_Exit()
            elif self.currentState == self.main.S022:
                self.S022_Exit()
        # end def
        def EventHandle(self, e, params):
            if self.currentState == self.main.S02Rgn1:
                return self.S02Rgn1_EventHandle(e, params)
            elif self.currentState == self.main.S022:
                return self.S022_EventHandle(e, params)
        # end def
        def EndTrans(self):
            self.currentState = self.targetState
            self.isExternalTrans = False
            if self.currentState == self.main.S02Rgn1:
                self.S02Rgn1_Enter()
            elif self.currentState == self.main.S022:
                self.S022_Enter()
        # end def
    # Region sub-class
    class _S0Rgn1Hsm(Statemachine):
        # Region implementation: S0Rgn1
        def S021_Enter(self):
            if self.Enterable(self.main.S021):
                self.S02_Enter()
                self.DefaultEntryAction('S021')
        # end def
        def S021_EventHandle(self, e, params):
            self.sourceState = self.main.S021
            return self.S02_EventHandle(e, params)
        # end def
        def S021_Exit(self):
            if self.Exitable(self.main.S021):
                self.DefaultExitAction('S021')
                self.S02_Exit()
        # end def
        def S02_Enter(self):
            if self.Enterable(self.main.S02):
                self.S0Rgn1_Enter()
                if self.targetState == self.main.S02:
                    self.pseudoState = self.main.InitialPseudostate2
                self.main.ShallowHistoryPseudostate1 = (self.main.ShallowHistoryPseudostate1 & ~self.main.S0Rgn1) | self.main.S02
                if self.main.S02Rgn1Hsm.pseudoState == 0:
                    self.main.S02Rgn1Hsm.pseudoState = self.main.S02Rgn1
                self.main.S02Rgn1Hsm.lastEnteredStateRecovering = self.lastEnteredStateRecovering
                self.main.S02Rgn1Hsm.regionMask = self.main.S02Rgn1
                self.main.S02Rgn1Hsm.BgnTrans(self.main.S02Rgn1Hsm.pseudoState)
                self.main.S02Rgn1Hsm.EndTrans()
                self.DefaultEntryAction('S02')
        # end def
        def S02_EventHandle(self, e, params):
            self.sourceState = self.main.S02
            if e == Events.E4:
                self.BgnTrans(self.main.S04)
                self.EndTrans()
                return True
            return self.S0Rgn1_EventHandle(e, params)
        # end def
        def S02_Exit(self):
            if self.Exitable(self.main.S02):
                self.main.S02Rgn1Hsm.BgnTrans(0)
                self.main.S02Rgn1Hsm.EndTrans()
                self.DefaultExitAction('S02')
                self.S0Rgn1_Exit()
        # end def
        def S04_Enter(self):
            if self.Enterable(self.main.S04):
                self.S0Rgn1_Enter()
                self.main.ShallowHistoryPseudostate1 = (self.main.ShallowHistoryPseudostate1 & ~self.main.S0Rgn1) | self.main.S04
                self.DefaultEntryAction('S04')
        # end def
        def S04_EventHandle(self, e, params):
            self.sourceState = self.main.S04
            return self.S0Rgn1_EventHandle(e, params)
        # end def
        def S04_Exit(self):
            if self.Exitable(self.main.S04):
                self.DefaultExitAction('S04')
                self.S0Rgn1_Exit()
        # end def
        def S0Rgn1_Enter(self):
            if self.Enterable(self.main.S0Rgn1):
                if self.targetState == self.main.S0Rgn1:
                    self.pseudoState = self.main.S0_Rgn1_Init
                if self.lastEnteredStateRecovering:
                    self.pseudoState = self.main.lastEnteredState & self.main.S0Rgn1
                self.DefaultEntryAction('S0Rgn1')
        # end def
        def S0Rgn1_EventHandle(self, e, params):
            self.sourceState = self.main.S0Rgn1
            return False
        # end def
        def S0Rgn1_Exit(self):
            if self.Exitable(self.main.S0Rgn1):
                self.DefaultExitAction('S0Rgn1')
        # end def
        def DefaultTrans(self):
            self.sourceState = self.currentState
            self.lcaState = 0
            if self.pseudoState == self.main.InitialPseudostate2:
                self.BgnTrans(self.main.S021)
                self.EndTrans()
                return True
            elif self.pseudoState == self.main.S0_Rgn1_Init:
                if self.main.ShallowHistoryPseudostate1 != 0:
                    self.lastEnteredStateRecovering = True
                    self.BgnTrans(self.main.ShallowHistoryPseudostate1 & self.main.S0Rgn1)
                    self.EndTrans()
                else:
                    self.BgnTrans(self.main.S02)
                    self.EndTrans()
                return True
            elif self.currentState != 0 and self.currentState != self.pseudoState:
                self.BgnTrans(self.pseudoState)
                self.EndTrans()
                return True
            self.lastEnteredStateRecovering = False
            return False
        # end def
        def BgnTrans(self, targetState):
            self.targetState = targetState
            self.pseudoState = targetState
            if self.currentState == self.main.S0Rgn1:
                self.S0Rgn1_Exit()
            elif self.currentState == self.main.S021:
                self.S021_Exit()
            elif self.currentState == self.main.S02:
                self.S02_Exit()
            elif self.currentState == self.main.S04:
                self.S04_Exit()
        # end def
        def EventHandle(self, e, params):
            if self.currentState == self.main.S0Rgn1:
                return self.S0Rgn1_EventHandle(e, params)
            elif self.currentState == self.main.S021:
                return self.S021_EventHandle(e, params)
            elif self.currentState == self.main.S02:
                return self.S02_EventHandle(e, params)
            elif self.currentState == self.main.S04:
                return self.S04_EventHandle(e, params)
        # end def
        def EndTrans(self):
            self.currentState = self.targetState
            self.isExternalTrans = False
            if self.currentState == self.main.S0Rgn1:
                self.S0Rgn1_Enter()
            elif self.currentState == self.main.S021:
                self.S021_Enter()
            elif self.currentState == self.main.S02:
                self.S02_Enter()
            elif self.currentState == self.main.S04:
                self.S04_Enter()
        # end def
    # Region sub-class
    class _S0Rgn2Hsm(Statemachine):
        # Region implementation: S0Rgn2
        def SubmachineState0_Enter(self):
            if self.Enterable(self.main.SubmachineState0):
                self.S0Rgn2_Enter()
                self.main.SubmachineState0Hsm.Initiate(self.lastEnteredStateRecovering)
                self.DefaultEntryAction('SubmachineState0')
        # end def
        def SubmachineState0_EventHandle(self, e, params):
            self.sourceState = self.main.SubmachineState0
            return self.S0Rgn2_EventHandle(e, params)
        # end def
        def SubmachineState0_Exit(self):
            if self.Exitable(self.main.SubmachineState0):
                self.main.SubmachineState0Hsm.Terminate()
                self.DefaultExitAction('SubmachineState0')
                self.S0Rgn2_Exit()
        # end def
        def S0Rgn2_Enter(self):
            if self.Enterable(self.main.S0Rgn2):
                if self.targetState == self.main.S0Rgn2:
                    self.pseudoState = self.main.S0_Rgn2_Init
                if self.lastEnteredStateRecovering:
                    self.pseudoState = self.main.lastEnteredState & self.main.S0Rgn2
                self.DefaultEntryAction('S0Rgn2')
        # end def
        def S0Rgn2_EventHandle(self, e, params):
            self.sourceState = self.main.S0Rgn2
            return False
        # end def
        def S0Rgn2_Exit(self):
            if self.Exitable(self.main.S0Rgn2):
                self.main.DeepHistoryPseudostate0 = self.main.lastEnteredState
                self.DefaultExitAction('S0Rgn2')
        # end def
        def DefaultTrans(self):
            self.sourceState = self.currentState
            self.lcaState = 0
            if self.pseudoState == self.main.SubmachineState0Hsm.ExitPoint0:
                self.main.ShallowHistoryPseudostate0 = 0
                self.BgnTrans(self.main.S0Rgn2)
                self.EndTrans()
                return True
            elif self.pseudoState == self.main.S0_Rgn2_Init:
                if self.main.DeepHistoryPseudostate0 != 0:
                    self.lastEnteredStateRecovering = True
                    self.BgnTrans(self.main.DeepHistoryPseudostate0 & self.main.S0Rgn2)
                    self.EndTrans()
                else:
                    self.BgnTrans(self.main.SubmachineState0)
                    self.EndTrans()
                return True
            elif self.currentState != 0 and self.currentState != self.pseudoState:
                self.BgnTrans(self.pseudoState)
                self.EndTrans()
                return True
            self.lastEnteredStateRecovering = False
            return False
        # end def
        def BgnTrans(self, targetState):
            self.targetState = targetState
            self.pseudoState = targetState
            if self.currentState == self.main.S0Rgn2:
                self.S0Rgn2_Exit()
            elif self.currentState == self.main.SubmachineState0:
                self.SubmachineState0_Exit()
        # end def
        def EventHandle(self, e, params):
            if self.currentState == self.main.S0Rgn2:
                return self.S0Rgn2_EventHandle(e, params)
            elif self.currentState == self.main.SubmachineState0:
                return self.SubmachineState0_EventHandle(e, params)
        # end def
        def EndTrans(self):
            self.currentState = self.targetState
            self.isExternalTrans = False
            if self.currentState == self.main.S0Rgn2:
                self.S0Rgn2_Enter()
            elif self.currentState == self.main.SubmachineState0:
                self.SubmachineState0_Enter()
        # end def
    # Region sub-class
    class _MainStmHsm(Statemachine):
        # Region implementation: MainStm
        def SubmachineState1_Enter(self):
            if self.Enterable(self.main.SubmachineState1):
                self.MainStm_Enter()
                self.main.SubmachineState1Hsm.Initiate(self.lastEnteredStateRecovering)
                self.DefaultEntryAction('SubmachineState1')
        # end def
        def SubmachineState1_EventHandle(self, e, params):
            self.sourceState = self.main.SubmachineState1
            return self.MainStm_EventHandle(e, params)
        # end def
        def SubmachineState1_Exit(self):
            if self.Exitable(self.main.SubmachineState1):
                self.main.SubmachineState1Hsm.Terminate()
                self.DefaultExitAction('SubmachineState1')
                self.MainStm_Exit()
        # end def
        def S011_Enter(self):
            if self.Enterable(self.main.S011):
                self.S01_Enter()
                self.DefaultEntryAction('S011')
        # end def
        def S011_EventHandle(self, e, params):
            self.sourceState = self.main.S011
            return self.S01_EventHandle(e, params)
        # end def
        def S011_Exit(self):
            if self.Exitable(self.main.S011):
                self.DefaultExitAction('S011')
                self.S01_Exit()
        # end def
        def S01_Enter(self):
            if self.Enterable(self.main.S01):
                self.S0_Enter()
                if self.targetState == self.main.S01:
                    self.pseudoState = self.main.InitialPseudostate0
                self.main.ShallowHistoryPseudostate0 = (self.main.ShallowHistoryPseudostate0 & ~self.main.MainStm) | self.main.S01
                if self.main.S01Rgn1Hsm.pseudoState == 0:
                    self.main.S01Rgn1Hsm.pseudoState = self.main.S01Rgn1
                self.main.S01Rgn1Hsm.lastEnteredStateRecovering = self.lastEnteredStateRecovering
                self.main.S01Rgn1Hsm.regionMask = self.main.S01Rgn1
                self.main.S01Rgn1Hsm.BgnTrans(self.main.S01Rgn1Hsm.pseudoState)
                self.main.S01Rgn1Hsm.EndTrans()
                self.DefaultEntryAction('S01')
        # end def
        def S01_EventHandle(self, e, params):
            self.sourceState = self.main.S01
            if e == Events.eLocal:
                self.BgnTrans(self.main.S0)
                self.EndTrans()
                return True
            elif e == Events.E3:
                self.BgnTrans(self.main.S03)
                self.EndTrans()
                return True
            return self.S0_EventHandle(e, params)
        # end def
        def S01_Exit(self):
            if self.Exitable(self.main.S01):
                self.main.S01Rgn1Hsm.BgnTrans(0)
                self.main.S01Rgn1Hsm.EndTrans()
                self.DefaultExitAction('S01')
                self.S0_Exit()
        # end def
        def S03_Enter(self):
            if self.Enterable(self.main.S03):
                self.S0_Enter()
                self.main.ShallowHistoryPseudostate0 = (self.main.ShallowHistoryPseudostate0 & ~self.main.MainStm) | self.main.S03
                self.DefaultEntryAction('S03')
        # end def
        def S03_EventHandle(self, e, params):
            self.sourceState = self.main.S03
            return self.S0_EventHandle(e, params)
        # end def
        def S03_Exit(self):
            if self.Exitable(self.main.S03):
                self.DefaultExitAction('S03')
                self.S0_Exit()
        # end def
        def S0_Enter(self):
            if self.Enterable(self.main.S0):
                self.State2_Enter()
                if self.targetState == self.main.S0:
                    self.pseudoState = self.main.S0_Init
                if self.main.S0Rgn1Hsm.pseudoState == 0:
                    self.main.S0Rgn1Hsm.pseudoState = self.main.S0Rgn1
                self.main.S0Rgn1Hsm.lastEnteredStateRecovering = self.lastEnteredStateRecovering
                self.main.S0Rgn1Hsm.regionMask = self.main.S0Rgn1
                self.main.S0Rgn1Hsm.BgnTrans(self.main.S0Rgn1Hsm.pseudoState)
                self.main.S0Rgn1Hsm.EndTrans()
                if self.main.S0Rgn2Hsm.pseudoState == 0:
                    self.main.S0Rgn2Hsm.pseudoState = self.main.S0Rgn2
                self.main.S0Rgn2Hsm.lastEnteredStateRecovering = self.lastEnteredStateRecovering
                self.main.S0Rgn2Hsm.regionMask = self.main.S0Rgn2
                self.main.S0Rgn2Hsm.BgnTrans(self.main.S0Rgn2Hsm.pseudoState)
                self.main.S0Rgn2Hsm.EndTrans()
                self.DefaultEntryAction('S0')
        # end def
        def S0_EventHandle(self, e, params):
            self.sourceState = self.main.S0
            return self.State2_EventHandle(e, params)
        # end def
        def S0_Exit(self):
            if self.Exitable(self.main.S0):
                self.main.S0Rgn1Hsm.BgnTrans(0)
                self.main.S0Rgn1Hsm.EndTrans()
                self.main.S0Rgn2Hsm.BgnTrans(0)
                self.main.S0Rgn2Hsm.EndTrans()
                self.DefaultExitAction('S0')
                self.State2_Exit()
        # end def
        def State2_Enter(self):
            if self.Enterable(self.main.State2):
                self.MainStm_Enter()
                if self.targetState == self.main.State2:
                    self.pseudoState = self.main.State2_Init
                self.DefaultEntryAction('State2')
        # end def
        def State2_EventHandle(self, e, params):
            self.sourceState = self.main.State2
            if e == Events.E0:
                if gVar > 3:
                    x = input("Enter x:")
                    if x > 3:
                        y = input("Enter y:")
                        if y > 3:
                            self.main.S0Rgn1Hsm.pseudoState = self.main.S021
                        else:
                            self.main.S02Rgn1Hsm.pseudoState = self.main.S022
                        # end if
                    else:
                        if x > 2:
                            self.isExternalTrans = True
                            self.BgnTrans(self.main.S011)
                            self.EndTrans()
                        else:
                            self.main.S01Rgn1Hsm.pseudoState = self.main.S012
                        # end if
                    # end if
                return True
                # end if
            elif e == Events.E2:
                # begin joining
                if IsIn(self.main.S0Rgn1Hsm.currentState, self.main.S021)\
                :
                    self.isExternalTrans = True
                    self.BgnTrans(self.main.S0)
                    self.EndTrans()
                # end joining
                else:
                    self.main.S0Rgn2Hsm.BgnTrans(self.main.SubmachineState0)
                    self.main.SubmachineState0Hsm.Initiate(self.lastEnteredStateRecovering, self.main.SubmachineState0Hsm.EntryPt0)
                    self.main.S0Rgn2Hsm.EndTrans()
                # end if
                return True
            elif e == Events.E1:
                # begin forking
                self.isExternalTrans = True
                self.BgnTrans(self.main.State2)
                self.main.S02Rgn1Hsm.pseudoState = self.main.S022
                self.main.S0Rgn1Hsm.pseudoState = self.main.S021
                self.EndTrans()
                # end forking
                return True
            return self.MainStm_EventHandle(e, params)
        # end def
        def State2_Exit(self):
            if self.Exitable(self.main.State2):
                self.DefaultExitAction('State2')
                self.MainStm_Exit()
        # end def
        def MainStm_Enter(self):
            if self.Enterable(self.main.MainStm):
                if self.targetState == self.main.MainStm:
                    self.pseudoState = self.main.MainStm_Init
                if self.lastEnteredStateRecovering:
                    self.pseudoState = self.main.lastEnteredState & self.main.MainStm
                self.DefaultEntryAction('MainStm')
        # end def
        def MainStm_EventHandle(self, e, params):
            self.sourceState = self.main.MainStm
            return False
        # end def
        def MainStm_Exit(self):
            if self.Exitable(self.main.MainStm):
                self.DefaultExitAction('MainStm')
        # end def
        def DefaultTrans(self):
            self.sourceState = self.currentState
            self.lcaState = 0
            if self.pseudoState == self.main.S0_Init:
                if self.main.ShallowHistoryPseudostate0 != 0:
                    self.lastEnteredStateRecovering = True
                    self.BgnTrans(self.main.ShallowHistoryPseudostate0 & self.main.MainStm)
                    self.EndTrans()
                else:
                    self.BgnTrans(self.main.S01)
                    self.EndTrans()
                return True
            elif self.currentState == self.main.S0\
                and self.main.S0Rgn1Hsm.pseudoState == self.main.S0Rgn1\
                and self.main.S0Rgn2Hsm.pseudoState == self.main.S0Rgn2\
            :
                return True
                self.BgnTrans(self.main.MainStm)
                self.EndTrans()
            elif self.pseudoState == self.main.MainStm_Init:
                if gVar == 0:
                    self.BgnTrans(self.main.SubmachineState1)
                    self.EndTrans()
                else:
                    self.BgnTrans(self.main.S0)
                    self.EndTrans()
                # end if
                return True
            elif self.pseudoState == self.main.State2_Init:
                self.BgnTrans(self.main.S0)
                self.EndTrans()
                return True
            elif self.pseudoState == self.main.InitialPseudostate0:
                self.BgnTrans(self.main.S011)
                self.EndTrans()
                return True
            elif self.currentState != 0 and self.currentState != self.pseudoState:
                self.BgnTrans(self.pseudoState)
                self.EndTrans()
                return True
            self.lastEnteredStateRecovering = False
            return False
        # end def
        def BgnTrans(self, targetState):
            self.targetState = targetState
            self.pseudoState = targetState
            if self.currentState == self.main.MainStm:
                self.MainStm_Exit()
            elif self.currentState == self.main.SubmachineState1:
                self.SubmachineState1_Exit()
            elif self.currentState == self.main.S011:
                self.S011_Exit()
            elif self.currentState == self.main.S01:
                self.S01_Exit()
            elif self.currentState == self.main.S03:
                self.S03_Exit()
            elif self.currentState == self.main.S0:
                self.S0_Exit()
            elif self.currentState == self.main.State2:
                self.State2_Exit()
        # end def
        def EventHandle(self, e, params):
            if self.currentState == self.main.MainStm:
                return self.MainStm_EventHandle(e, params)
            elif self.currentState == self.main.SubmachineState1:
                return self.SubmachineState1_EventHandle(e, params)
            elif self.currentState == self.main.S011:
                return self.S011_EventHandle(e, params)
            elif self.currentState == self.main.S01:
                return self.S01_EventHandle(e, params)
            elif self.currentState == self.main.S03:
                return self.S03_EventHandle(e, params)
            elif self.currentState == self.main.S0:
                return self.S0_EventHandle(e, params)
            elif self.currentState == self.main.State2:
                return self.State2_EventHandle(e, params)
        # end def
        def EndTrans(self):
            self.currentState = self.targetState
            self.isExternalTrans = False
            if self.currentState == self.main.MainStm:
                self.MainStm_Enter()
            elif self.currentState == self.main.SubmachineState1:
                self.SubmachineState1_Enter()
            elif self.currentState == self.main.S011:
                self.S011_Enter()
            elif self.currentState == self.main.S01:
                self.S01_Enter()
            elif self.currentState == self.main.S03:
                self.S03_Enter()
            elif self.currentState == self.main.S0:
                self.S0_Enter()
            elif self.currentState == self.main.State2:
                self.State2_Enter()
        # end def
    def __init__(self, _main, _stateBitShift, _parent):
        super().__init__(_main, _stateBitShift, _parent)
        # States definitions
        self.MainStm_Init = self.MakeState(MainTop.Bit_MainStm_Init)
        self.SubmachineState1 = self.MakeState(MainTop.Bit_SubmachineState1)
        self.S0_Init = self.MakeState(MainTop.Bit_S0_Init)
        self.S011 = self.MakeState(MainTop.Bit_S011)
        self.InitialPseudostate0 = self.MakeState(MainTop.Bit_InitialPseudostate0)
        self.S01 = self.S011 | self.InitialPseudostate0
        self.S012 = self.MakeState(MainTop.Bit_S012)
        self.InitialPseudostate1 = self.MakeState(MainTop.Bit_InitialPseudostate1)
        self.S01Rgn1 = self.S012 | self.InitialPseudostate1
        self.S03 = self.MakeState(MainTop.Bit_S03)
        self.S0 = self.S0_Init | self.S01 | self.S03
        self.S0_Rgn1_Init = self.MakeState(MainTop.Bit_S0_Rgn1_Init)
        self.S021 = self.MakeState(MainTop.Bit_S021)
        self.InitialPseudostate2 = self.MakeState(MainTop.Bit_InitialPseudostate2)
        self.S02 = self.S021 | self.InitialPseudostate2
        self.S022 = self.MakeState(MainTop.Bit_S022)
        self.InitialPseudostate3 = self.MakeState(MainTop.Bit_InitialPseudostate3)
        self.S02Rgn1 = self.S022 | self.InitialPseudostate3
        self.S04 = self.MakeState(MainTop.Bit_S04)
        self.S0Rgn1 = self.S0_Rgn1_Init | self.S02 | self.S04
        self.SubmachineState0 = self.MakeState(MainTop.Bit_SubmachineState0)
        self.S0_Rgn2_Init = self.MakeState(MainTop.Bit_S0_Rgn2_Init)
        self.S0Rgn2 = self.SubmachineState0 | self.S0_Rgn2_Init
        self.State2_Init = self.MakeState(MainTop.Bit_State2_Init)
        self.State2 = self.S0 | self.State2_Init
        self.MainStm = self.MainStm_Init | self.SubmachineState1 | self.State2
        self.stateCount = MainTop.StateCount
        # sub-machine and regions declaration
        self.MainStmHsm = self._MainStmHsm(self, self.stateBitShift, self.parent)
        self.SubmachineState1Hsm = SharedTop(self, self.stateBitShift + MainTop.Bit_SubmachineState1, self.MainStmHsm)
        self.S01Rgn1Hsm = self._S01Rgn1Hsm(self, self.stateBitShift, self.parent)
        self.ShallowHistoryPseudostate0 = 0
        self.S0Rgn1Hsm = self._S0Rgn1Hsm(self, self.stateBitShift, self.parent)
        self.S02Rgn1Hsm = self._S02Rgn1Hsm(self, self.stateBitShift, self.parent)
        self.ShallowHistoryPseudostate1 = 0
        self.S0Rgn2Hsm = self._S0Rgn2Hsm(self, self.stateBitShift, self.parent)
        self.SubmachineState0Hsm = SharedTop(self, self.stateBitShift + MainTop.Bit_SubmachineState0, self.S0Rgn2Hsm)
        self.DeepHistoryPseudostate0 = 0
    def EventHandle(self, e, params):
        result = False
        result = self.S01Rgn1Hsm.EventHandle(e, params) or result
        result = self.S02Rgn1Hsm.EventHandle(e, params) or result
        result = self.S0Rgn1Hsm.EventHandle(e, params) or result
        result = self.SubmachineState0Hsm.EventHandle(e, params) or self.S0Rgn2Hsm.EventHandle(e, params) or result
        result = self.SubmachineState1Hsm.EventHandle(e, params) or self.MainStmHsm.EventHandle(e, params) or result
        return result
    # end def
    def DefaultTrans(self):
        while True:
            result = False
            result = self.S01Rgn1Hsm.DefaultTrans() or result
            result = self.S02Rgn1Hsm.DefaultTrans() or result
            result = self.S0Rgn1Hsm.DefaultTrans() or result
            result = self.SubmachineState0Hsm.DefaultTrans() or self.S0Rgn2Hsm.DefaultTrans() or result
            result = self.SubmachineState1Hsm.DefaultTrans() or self.MainStmHsm.DefaultTrans() or result
            if result == False:
                break
        # end loop
    # end def
    def Initiate(self, lastEnteredStateRecovering, entryPoint = 0):
        if entryPoint != 0:
            self.MainStmHsm.pseudoState = entryPoint
            return
        if self.MainStmHsm.pseudoState == 0:
            self.MainStmHsm.pseudoState = self.MainStm
        self.MainStmHsm.lastEnteredStateRecovering = lastEnteredStateRecovering
        self.MainStmHsm.regionMask = self.MainStm
        self.MainStmHsm.BgnTrans(self.MainStmHsm.pseudoState)
        self.MainStmHsm.EndTrans()
    # end def
    def Terminate(self):
        self.MainStmHsm.BgnTrans(0)
        self.MainStmHsm.EndTrans()
    # end def







stm = MainTop(None, 0, None)
def main():

    stm.Initiate(False)
    stm.DefaultTrans()


    print("-------------1--------------")
    stm.EventHandle(Events.E10, any)
    stm.DefaultTrans()

    print("-------------2--------------")
    stm.EventHandle(Events.E3, any)
    stm.DefaultTrans()

    print("-------------3--------------")
    stm.EventHandle(Events.E2, any)
    stm.DefaultTrans()


if __name__ == "__main__":
    main()

