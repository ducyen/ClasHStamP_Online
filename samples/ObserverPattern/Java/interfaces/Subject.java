/* File generated by Đức's ClasHStamP */
package interfaces;

import java.io.*;
import java.util.*;
import interfaces.*;

public  interface Subject
{
    public  void registerObserver(
        ObserverIfc o
    );
    public  void removeObserver(
        ObserverIfc o
    );
    public  void notifyObserver(
    );
}
