FROM debian:11.0

RUN apt-get update
RUN apt-get install -y php-fpm

EXPOSE 9000

CMD [ "/usr/bin/php", "-f" ]
# php-fpm을 실행할 수가 없음
# php-fpm을 실행할 수 있는 경로를 찾아야 함
# how?