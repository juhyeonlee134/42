FROM debian:11.0

RUN apt-get update
RUN apt-get install -y php-fpm

COPY ./conf/php.ini /etc/php/7.4/fpm/php.ini
EXPOSE 9000

CMD [ "/usr/bin/php", "-f" ]