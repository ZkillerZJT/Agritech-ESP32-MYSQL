# Agritech-ESP32-MYSQL
Este es un repositorio que almacena el código a utilizar para realizar una conexión a una base de datos Hospedada en AIVEN, con infraestructura de AWS como proveedor de Base de datos en la nube.
# Setup
Se utilizan datos confidenciales como usuario, hostname, contraseñas, certificados en un archivo que deberás llamar "credentials.h", por razones de seguridad, no se subirá a este repositorio y en caso de que repliques este proyecto, deberás obtener tus propias "credentials.h", las cuales son información que se encuentra mencionada en el readme.md
requisitos previos:
-Tener instalado y usar Arduino IDE
-Utilizar librería ESP32-MySQL disponible en el gesto de librerías del Arduino IDE.
-Configurar tu ESP32 en el Arduino IDE para luego subir el código a este microchip, cabe mencionar que este debe estar conectado por USB al computador al momento de subir el código al microchip.
-Obtener credenciales desde tu propia base de datos, hosteada en Aiven o cualquier otro sitio mientras te provean de la siguiente información:
1)Hostname o dirección IP de la base de datos.
2)Usuario y contraseña para acceder a la base de datos.
3)Certificado SSL propio de la base de datos, para ser usado en conexiones HTTPS con cifrado SSL/TLS1.3.
4)Puerto de conexión a la base de datos.
Una vez realizados estos pasos previos, se puede implementar el código del repositorio en tu proyecto.
Este código busca recopilar información de sensores, conectarse a internet y luego a la base de datos, para finalmente ingresar la información leída por los sensores a la base de datos.
El microchip se encargará de todo este procedimiento, y en esta fase inicial de desarrollo, estaremos poniendo a prueba el uso de certificados SSL para conexiones seguras con una base de datos en la nube.
Momentáneamente, estaremos intentando crear una tabla en la base de datos, implementación completa se encuentra en progreso.
# EN PROCESO DE CONSTRUCCIÓN!
Este proyecto no se encuentra completo, y no se garantiza su correcto funcionamiento hasta que en este apartado se indique explícitamente, personalmente modificaré esta documentación una vez este código sea funcional.

