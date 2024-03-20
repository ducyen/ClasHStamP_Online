{ pkgs }: {
	deps = [
        pkgs.xdotool
        pkgs.xterm
        pkgs.unzip
        # pkgs.zulu8                    # java 1.8.0_265 to run astah-com
        pkgs.adoptopenjdk-hotspot-bin-8 # java 1.8.0_292 to run astah-uml
        pkgs.imagemagick6
        pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}