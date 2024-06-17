.PHONY	: build up down all re

build	:
	docker-compose -f ./srcs/docker-compose.yml build
up		:
	docker-compose -f ./srcs/docker-compose.yml up -d
down	:
	docker-compose -f ./srcs/docker-compose.yml down
	docker rmi nginx
	docker rmi wordpress
	docker rmi mariadb
all		: build up
re		: down build up