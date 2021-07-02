import csv
import serial
import _thread
import visualization_taichi


def csv_write(lines):
    out = open('save.csv', 'a', newline='')
    csv_write = csv.writer(out, dialect='excel')
    csv_write.writerow(lines)


def read_serial(port_name, port_number):
    ser = serial.Serial(port_name, port_number)
    while True:
        s = ser.readline()
        s_format_output = []
        s_format = str(s).split("'")
        s_format = str(s_format[1]).split("\\t")
        for i in range(len(s_format)):
            if "\\" in s_format[i]:
                temp = str(s_format[i]).split('\\')
                s_format_output += temp[0].split(':')
            else:
                s_format_output += str(s_format[i]).split(':')
        s_format_trans = [float(i) for i in s_format_output]
        if len(s_format_trans) == 4:
            visualization_taichi.transform(s_format_trans)


if __name__ == '__main__':
    try:
        _thread.start_new_thread(read_serial, ('/dev/cu.usbmodem142401', 9600))
        visualization_taichi.main()
    except Exception as e:
        print(str(e))
