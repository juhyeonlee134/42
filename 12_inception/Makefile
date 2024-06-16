.PHONY	: up down re

up		:
	docker build -t nginx ./nginx
	docker build -t wordpress ./wordpress
	docker-compose up -d
down	:
	docker-compose down -v
	docker rmi nginx
	docker rmi wordpress
re		: down up