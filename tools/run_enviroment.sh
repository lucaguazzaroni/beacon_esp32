#!/bin/bash

IMAGE_NAME="espressif/idf"
IMAGE_TAG="release-v4.3"

check_image=$(docker images --format={{.Repository}}:{{.Tag}} | grep -w $IMAGE_NAME:$IMAGE_TAG)

if [[ $check_image ]]; then
    echo "$IMAGE_NAME:$IMAGE_TAG already exists"
else
    echo "Pulling $IMAGE_NAME:$IMAGE_TAG.."
    docker pull $IMAGE_NAME:$IMAGE_TAG
fi

echo "Creating container..."
docker run --privileged --rm -it -v /dev:/dev -v $PWD:/project -w /project $IMAGE_NAME:$IMAGE_TAG bash
