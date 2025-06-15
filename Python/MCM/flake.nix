{
  description = "A basic flake with a shell";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs =
    {
      nixpkgs,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs {
          system = "${system}";
          config.allowUnfree = true;
        };
      in
      {
        devShells.default = pkgs.mkShell {
          allowUnfree = true;
          packages = [
            # pkgs.cudaPackages_12_1.cudatoolkit
            # pkgs.gcc14
            (pkgs.python310.withPackages (
              ps: with ps; [
                numpy
                matplotlib
                # torch-bin
              ]
            ))
          ];
          # shellHook = ''
          #   export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:${pkgs.cudaPackages_12_1.cudatoolkit}/lib64:/run/opengl-driver/lib"
          # '';
        };
      }
    );
}
