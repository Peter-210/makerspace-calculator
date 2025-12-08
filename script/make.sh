#!/bin/bash


print_help() {
	cat <<EOF
Usage: $0 [OPTIONS]

Run and Manage CMake Build

Options:
	-h, --help    			  Show this help message and exit
	-d, --debug						Build project to run in debug mode
	-t, --test						Build project to run in test mode. May need to clean (-c) before use
	-c, --clean						Remove build files
	-l, --lib-clean				Remove lib files (eg. googletest)

EOF
}


if [[ $# -eq 0 ]]; then
    print_help
    exit 1
fi

while test $# -gt 0; do
	case "$1" in
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

			echo "Start cleaning..."

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

			echo "Start cleaning libraries..."

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
