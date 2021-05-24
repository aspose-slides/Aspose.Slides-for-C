call "../setup_php_environment.bat"

php -n -e -c AsposeSlidesCppExtension.ini -r " echo convert_to_pdf('./Files/HelloWorld.pptx','./Files/HelloWorld.pdf');"
