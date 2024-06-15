FROM debian:11.0

RUN apt-get update
RUN apt-get install -y mariadb-server

EXPOSE 3306

CMD [ "/usr/bin/mariadb" ]