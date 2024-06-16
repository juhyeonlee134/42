.PHONY	: up down

up		:
	docker build -t nginx ./nginx
	docker-compose up -d
down	:
	docker-compose down -v
	docker rmi nginx