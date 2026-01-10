#!/bin/bash

CURR_FILE_PATH="$0"
CURR_DIR_PATH="${CURR_FILE_PATH%/*}"

cd $CURR_DIR_PATH
cd ../

PROJECT_NAME="${PWD##*/}"

sed -i "s/\(container_name: \).*/\1$PROJECT_NAME/g" "docker-compose.yml"
sed -i "s/\(CONTAINER_NAME=\).*/\1$PROJECT_NAME/g" "script/docker.sh"

sed -i "2s/.*/  ${PROJECT_NAME}:/" "docker-compose.yml"
sed -i "s/extends:.*/extends: ${PROJECT_NAME}/" "docker-compose.yml"
sed -i "s/\(IMAGE_PROD_NAME=\).*/\1${PROJECT_NAME}-prod/g" "script/docker.sh"
sed -i "s/\(IMAGE_DEV_NAME=\).*/\1${PROJECT_NAME}-dev/g" "script/docker.sh"

sed -i "s/\(PROJECT_NAME           = \).*/\1\"${PROJECT_NAME}\"/g" "Doxyfile"

echo "Setup complete"
