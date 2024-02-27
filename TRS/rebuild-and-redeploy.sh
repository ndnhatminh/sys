#!/bin/sh

docker stop RecSys-Backend-core;
docker rm RecSys-Backend-core;
docker build --tag recsys-backend-core .;
docker run --name RecSys-Backend-core -d --net=recsys-network -p 5005:5005 \
    -v "$(pwd)"/logs:/app/logs \
    -v "$(pwd)"/files:/app/files \
    -v "$(pwd)"/solution:/app/solution \
    --restart always \
    recsys-backend-core;
exit;