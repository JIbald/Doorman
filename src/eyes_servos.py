
import RPi.GPIO as GPIO
import time

#set gpio numbering mode
GPIO.setmode(GPIO.BOARD)

# LEFT EYE UP DOWN
GPIO.setup(11,GPIO.OUT)
servo_le_ud = GPIO.PWM(11, 50) #11 is pin, 50 = 50Hz pulse

# RIGHT EYE UP DOWN
GPIO.setup(22, GPIO.OUT)
servo_re_ud = GPIO.PWM(22, 50)

#start PWM running, but with value of 0 (pulse off)
# servo.start(dc)
# where dc is the duty cycle (0.0 <= dc <= 100.0)
servo_le_ud.start(0)
servo_re_ud.start(0)
print ("Waiting for 2 seconds")
time.sleep(2)

# front to back 180 degree
print ("front to back 45")
le_ud_duty =2
re_ud_duty = 12
while le_ud_duty <= 13 & re_ud_duty >= 2:
    servo_le_ud.ChangeDutyCycle(le_ud_duty)
    servo_re_ud.ChangeDutyCycle(re_ud_duty)
    time.sleep(1)
    le_ud_duty += 2
    re_ud_duty -= 2


#clean things up at the end
#doesn't move the servo
servo_le_ud.stop()
servo_re_ud.stop()
GPIO.cleanup()
print("Goodbye.")