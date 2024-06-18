.PHONY	: build start down start stop

build	:
	@docker-compose -f ./srcs/docker-compose.yml build

start	:
	@docker-compose -f ./srcs/docker-compose.yml start

up		:
	@docker-compose -f ./srcs/docker-compose.yml up

down	:
	@docker-compose -f ./srcs/docker-compose.yml down -v

stop	:
	@docker-compose -f ./srcs/docker-compose.yml stop