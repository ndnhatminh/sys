#!/bin/sh

docker stop RecSys-Service-Grader;
docker rm RecSys-Service-Grader;
docker build --tag recsys-service-grader .;
docker run --name RecSys-Service-Grader -d -p 5003:5003 \
    -v "$(pwd)"/logs:/app/logs \
    -v "$(pwd)"/grading_app/temp/grad_sub:/app/grading_app/temp/grad_sub \
    -v "$(pwd)"/grading_app/temp/init_grad_sub:/app/grading_app/temp/init_grad_sub \
    -v "$(pwd)"/output:/app/output \
    -v /root/code-practice/222FPA2-TRS-backend/files/submissions:/app/files/submissions \
    --net=recsys-network \
    --restart always \
    recsys-service-grader ;
exit;