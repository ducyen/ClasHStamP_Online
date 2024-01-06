{ pkgs }: {
	deps = [
   pkgs.unzip
   pkgs.zulu8
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}