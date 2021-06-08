service mysql start
service php7.3-fpm start
service nginx start
service nginx start

#if [ "${AUTOINDEX}" = "off" ]
#then
#	sed -i -e "s/autoindex on;/autoindex off;/" /etc/nginx/conf.d/default.conf
#fi

tail -f /dev/null
