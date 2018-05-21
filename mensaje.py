#twilio number +17084870008
from twilio.rest import Client
import serial

def sendMessage():
	# Your Account Sid and Auth Token from twilio.com/user/account
	account_sid = "ACbf13e76979fcdae1c5c5dac6d621c882"# Your Account SID from www.twilio.com/console
	auth_token = "c502ce3a49266a15265d5fd94fa0dea3" # Your Auth Token from www.twilio.com/console
	client = Client(account_sid, auth_token)
	
	message = client.messages.create(
	    "+5212222030334",
	    body="La comida de tu mascota se termino",
	    from_="+12244707751"
	)
	
	print(message.sid)


ser = serial.Serial('/dev/ttyACM0',9600)
while True:
	ser.readline()
	sendMessage()
