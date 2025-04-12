{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  buildInputs = [
    pkgs.gcc
    pkgs.gnumake
    pkgs.clang-tools
  ];

  shellHook = ''
    export SHELL=$(which zsh)
    exec $SHELL
  '';
}
