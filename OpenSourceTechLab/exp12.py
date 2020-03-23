# send an email in python

from getpass import getpass
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import smtplib

sender_name = input("Enter the sender's name: ")
sender_email = input("Enter the sender's email: ")
sender_password = getpass("Enter the password: ")
port = int(input("Enter the port number (default = 587): "))

receiver_email = input("Enter the receiver's email: ")
subject = input("Enter the subject: ")
body = input("Enter the body: ")

# for email id: test@gmail.com
# host = smtp.gmail.com
host = "smtp." + sender_email[sender_email.index("@") + 1:]

message = MIMEMultipart()
message["from"] = sender_name
message["to"] = receiver_email
message["subject"] = subject
message.attach(MIMEText(body))

with smtplib.SMTP(host=host, port=port) as smtp:
    # identify yourself to an ESMTP server.
    smtp.ehlo()
    # put the SMTP connection in TLS mode. All SMTP commands that follow will be encrypted.
    smtp.starttls()
    # call ehlo() again
    smtp.ehlo()
    smtp.login(sender_email, sender_password)
    smtp.send_message(message)
    print(f"Message sent to: {receiver_email}, from: {sender_email}")
