import smtplib
fromaddr = 'kazuhikoamamiyakun@gmail.com'
toaddrs = 'r0dra42@gmail.com'
msg = 'Email message from PYTHON Rodrigo app'

#provide gmail user name and password
username = 'kazuhikoamamiyakun'
password = 'bmbnbvd7'

# functions to send an email
server = smtplib.SMTP('smtp.gmail.com:587')
server.ehlo()
server.starttls()
server.ehlo()
server.login(username, password)
server.sendmail(fromaddr, toaddrs, msg)
server.quit()

