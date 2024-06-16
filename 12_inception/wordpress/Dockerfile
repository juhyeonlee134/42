FROM debian:11.0

RUN mkdir -p /run/php;
RUN apt-get update && apt-get upgrade -y;
RUN apt-get install -y php-fpm php-mysql;

COPY tools/run.sh /etc/php/run.sh

EXPOSE 9000

ENTRYPOINT [ "/bin/bash", "/etc/php/run.sh" ]