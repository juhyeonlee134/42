#!/bin/bash

mkdir /etc/nginx/ssl;

#RSA 알고리즘을 이용해 4096비트의 키를 생성하고 365일 동안 유효한 인증서를 생성
openssl req -x509 -newkey rsa:4096 -keyout $TLS_KEY_PATH -out $TLS_CERT_PATH -days 365 -nodes -subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=inception/CN=juhyelee@42.fr"

nginx -g "daemon off;"