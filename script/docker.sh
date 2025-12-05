#!/bin/bash

CONTAINER_NAME=makerspace-calculator

print_help() {
	cat <<EOF
Usage: $0 [OPTIONS]

Run and Manage Docker

Options:
	-h, --help    			  Show this help message and exit
	-d, --dev							Create container and image for developement (uses extra dev tools)
	-p, --prod						Create container and image for production (minimal dependencies)
	-c, --clean						Purge docker container and image

EOF
}

make_container() {
	docker-compose --profile "$1" up -d
	docker exec -it "$CONTAINER_NAME" /bin/bash
}

if [[ $# -eq 0 ]]; then
    print_help
    exit 1
fi

while test $# -gt 0; do
	case "$1" in
		-d|--dev)
			shift

			if test $# -gt 0; then
				echo "--dev cannot have more than one flag after it"
				exit 1
      fi

			echo "Starting docker in profile dev"
			make_container "dev"
			;;

		-p|--prod)
			shift

			if test $# -gt 0; then
				echo "--prod cannot have more than one flag after it"
				exit 1
      fi

			echo "Starting docker in profile prod"
			make_container "prod"
			;;

		-c|--clean)
			shift

			echo "Cleaning container and image"

			docker stop $(docker ps -aq)
			docker rm $(docker ps -aq)
			docker rmi -f $(docker images -q)
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
