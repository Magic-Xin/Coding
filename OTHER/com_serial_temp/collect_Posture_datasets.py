import csv
import serial
import sys


def csv_write(Lines):
    out = open('up+.csv', 'a', newline='')
    csv_write = csv.writer(out, dialect='excel')
    csv_write.writerow(Lines)


ser = serial.Serial('COM3', 115200)
count = 0
while True:
    s = ser.readline()  # 读取一行
    s_format_output = []
    s_format = str(s).split(' ')
    for i in range(len(s_format)):
        if "\\" in s_format[i]:
            temp = str(s_format[i]).split('\\')
            s_format_output += temp[0].split(':')
        else:
            s_format_output += str(s_format[i]).split(':')
    print(s_format_output)

    for i in range(len(s_format_output)):
        if s_format_output[i] == "rate":
            count += 1
            print("******************************" + str(count) + "****************************")
    csv_write(s_format_output)
