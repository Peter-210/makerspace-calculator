#!/bin/bash


print_help() {
	cat <<EOF
Usage: $0 [OPTIONS]

Run and Manage CMake Build

Options:
	-h, --help    			  Show this help message and exit
	-p, --prod						Build project to run in prod mode (Optimized version)
	-d, --debug						Build project to run in debug mode (GDB)
	-t, --test						Build project to run in test mode (GTest and GDB). May need to clean (-c) before use
	-c, --clean						Remove build files
	-l, --lib-clean				Remove lib files (eg. GTest)

EOF
}


if [[ $# -eq 0 ]]; then
    print_help
    exit 1
fi

CURR_FILE_PATH="$0"
CURR_DIR_PATH="${CURR_FILE_PATH%/*}"
cd $CURR_DIR_PATH
cd ../

while test $# -gt 0; do
	case "$1" in
		-p|--prod)
			shift

			if test $# -gt 0; then
				echo "--prod cannot have more than one flag after it"
				exit 1
      fi

			echo "Running cmake --workflow --preset main"
			cmake --workflow --preset main
			;;

		-d|--debug)
			shift

			if test $# -gt 0; then
				echo "--debug cannot have more than one flag after it"
				exit 1
      fi

			echo "Running cmake --workflow --preset debug"
			cmake --workflow --preset debug
			;;

		-t|--test)
			shift

			if test $# -gt 0; then
				echo "--test cannot have more than one flag after it"
				exit 1
      fi

			echo "Running cmake --workflow --preset testing"
			cmake --workflow --preset testing
			;;

		-c|--clean)
			shift

			echo "Cleaning build..."

			if [ -d "./build/" ]; then
				echo "Removing ./build/ folder"
				rm -rf ./build/
			fi

			if [ -L "./compile_commands.json" ]; then
				echo "Removing ./compile_commands.json file"
				rm ./compile_commands.json
			fi
			;;

		-l|--lib-clean)
			shift

			echo "Cleaning libraries..."

			if [ -d "./lib/" ]; then
				echo "Removing ./lib/ folder"
				rm -rf ./lib/
			fi
			;;

		-h|--help)
			shift
			print_help
			exit 1
			;;

		*)
			echo "Unknown option: $1" >&2
			echo "Use --help for usage."
			exit 1
			;;
	esac
done
