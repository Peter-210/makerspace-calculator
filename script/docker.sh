#!/bin/bash

CONTAINER_NAME=makerspace-calculator
IMAGE_PROD_NAME=makerspace-calculator-prod
IMAGE_DEV_NAME=makerspace-calculator-dev

print_help() {
	cat <<EOF
Usage: $0 [OPTIONS]

Run and Manage Docker

Options:
	-h, --help    			  Show this help message and exit
	-d, --dev							Create container and image for developement (uses extra dev tools)
	-p, --prod						Create container and image for production (minimal dependencies)
	-c, --clean						Purge docker container
	-i, --image-clean			Purge docker image (prod and dev)

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

CURR_FILE_PATH="$0"
CURR_DIR_PATH="${CURR_FILE_PATH%/*}"
cd $CURR_DIR_PATH
cd ../

while test $# -gt 0; do
	case "$1" in
		-d|--dev)
			shift

			if test $# -gt 0; then
				echo "--dev cannot have more than one flag after it"
				exit 1
      fi

			echo "Starting docker in profile dev..."
			make_container "dev"
			;;

		-p|--prod)
			shift

			if test $# -gt 0; then
				echo "--prod cannot have more than one flag after it"
				exit 1
      fi

			echo "Starting docker in profile prod..."
			make_container "prod"
			;;

		-c|--clean)
			shift

			echo "Cleaning container..."

			docker stop $CONTAINER_NAME
			docker rm $CONTAINER_NAME
			;;
			
		-i|--image-clean)
			shift

			echo "Cleaning images..."

			docker rmi $IMAGE_PROD_NAME
			docker rmi $IMAGE_DEV_NAME
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
