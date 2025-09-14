{ pkgs }: with pkgs; let SDL = [
    SDL2.dev
    SDL2_image
    SDL2_ttf
    SDL2_net
    SDL2_gfx
    # SDL2_sound
    SDL2_mixer
]; in
{
    deps = [
        dos2unix
        clang_12
        ccls
        gdb
        gnumake
        rnix-lsp  
        xdotool
        xterm
        unzip
        #zulu8                    # java 1.8.0_265 to run astah-com
        adoptopenjdk-hotspot-bin-8 # java 1.8.0_292 to run astah-uml
        imagemagick6
        chipmunk        
    ] ++ SDL;
    env = {
        CPLUS_INCLUDE_PATH = lib.makeSearchPath "include/SDL2" SDL;
    };    
}
