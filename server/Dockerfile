# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 23:53:43 by yoinoue           #+#    #+#              #
#    Updated: 2020/12/22 00:01:27 by yoinoue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#install image
FROM	debian:buster

RUN		set -eux; \
		apt update; \
	#nginx, MariaDB,phpインストール
		apt install -y --no-install-recommends	nginx \
							mariadb-server mariadb-client \
							php-cgi php-common php-fpm php-pear php-mbstring php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath \
							unzip wget git vim; \
		rm -rf /var/lib/apt/lists/*; \
	#systemdインストール
		apt update; \
		apt install -y systemd; \
		rm -rf /var/lib/apt/lists/*; \
	#MariaDB設定
		service mysql start; \
		echo "CREATE DATABASE wpdb;" | mysql -u root --skip-password; \
		echo "CREATE USER 'wpuser'@'localhost' identified by 'dbpassword';" | mysql -u root --skip-password; \
		echo "GRANT ALL PRIVILEGES ON wpdb.* TO 'wpuser'@'localhost';" | mysql -u root --skip-password; \
		echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;
		#echo "EXIT;" | mysql -u root --skip-password;
	#nginx, php7.3-fpm再起動
		#service nginx start; \
		#service php7.3-fpm start;

#wordpress設定
WORKDIR /var/www/html
RUN		wget --no-check-certificate https://wordpress.org/latest.tar.gz; \
		tar -xvzf latest.tar.gz; \
		rm latest.tar.gz;
WORKDIR /var/www/html/wordpress
RUN		cp wp-config-sample.php wp-config.php; \
		chown -R www-data:www-data /var/www/html;

#php7.3設定
WORKDIR	/var/run/
RUN		mkdir php; \
		touch php/php7.3-fpm.sock; \
		chmod 777 php/php7.3-fpm.sock;

#nginx設定
WORKDIR /etc/nginx/sites-available/
RUN		touch default.tmpl;
		#ln -s /etc/nginx/sites-available/default.tmpl /etc/nginx/sites-enabled/; \
		#rm -rf /etc/nginx/sites-enabled/default;

#SSL設定
RUN	apt update; \
	apt install openssl; \
	rm -rf /var/lib/apt/lists/*; \
	mkdir /etc/nginx/ssl; \
	openssl req -newkey rsa:4096 -x509 -sha256 -days 3650 -nodes -out /etc/nginx/ssl/wordpress.crt -keyout /etc/nginx/ssl/wordpress.key -subj "/C=JP/ST=Tokyo/L=Tokyo/O=42Tokyo/OU=Student/CN=wordpress/EA=";

#phpmyadmin設定
WORKDIR /tmp/
RUN	set -eux; \
	wget --no-check-certificate https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz; \
	tar -xvzf phpMyAdmin-5.0.2-all-languages.tar.gz; \
	rm phpMyAdmin-5.0.2-all-languages.tar.gz; \
	mv phpMyAdmin-5.0.2-all-languages phpmyadmin; \
	mv phpmyadmin /var/www/html/;

#Entrykitインストール for render
ENV	ENTRYKIT_VERSION 0.4.0
WORKDIR /
RUN	wget --no-check-certificate https://github.com/progrium/entrykit/releases/download/v${ENTRYKIT_VERSION}/entrykit_${ENTRYKIT_VERSION}_Linux_x86_64.tgz; \
	tar -xvzf entrykit_${ENTRYKIT_VERSION}_Linux_x86_64.tgz; \
	rm entrykit_${ENTRYKIT_VERSION}_Linux_x86_64.tgz; \
	mv entrykit /bin/entrykit; \
	chmod +x /bin/entrykit; \
	entrykit --symlink;

COPY	./srcs/php.ini				/etc/php/7.3/fpm/php.ini
#COPY	./srcs/phpmyadmin.inc.php	/var/www/html/phpmyadmin/config.inc.php
COPY	./srcs/wp-config.php		/var/www/html/wordpress/wp-config.php
COPY	./srcs/default.tmpl			/etc/nginx/sites-available/
COPY	./srcs/service_start.sh		/tmp/

#EntryPoint
ENTRYPOINT [ "render", "/etc/nginx/sites-available/default", "--", "bash", "/tmp/service_start.sh" ]

#nginx start
#CMD		nginx -g "daemon off;"
