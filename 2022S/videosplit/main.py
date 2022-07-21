import sys

import ffmpeg
import os


def split_flv_by_size(flv_file, size):
    output_dir = os.path.dirname(flv_file)
    output_dir = os.path.join(output_dir, 'split')
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)

    video_time = int(float(ffmpeg.probe(flv_file, cmd='ffprobe')['format']['duration']))
    video_bitrate = int(float(ffmpeg.probe(flv_file, cmd='ffprobe')['format']['bit_rate']))

    start_time = 0
    offset = 5
    i = 1

    while start_time < (video_time - offset):
        filename = 'P{}.flv'.format(i)
        output_file = os.path.join(output_dir, filename)
        split_length = size
        if i != 1:
            split_length = int(size + (video_bitrate * offset / 8))
        record_start_time = start_time
        if i != 1:
            record_start_time = start_time - offset

        print('Splitting {}'.format(filename))
        ffmpeg.input(flv_file).output(output_file, format='flv', vcodec='copy', acodec='copy', ss=record_start_time,
                                      fs=split_length).run()

        start_time = start_time + int(float(ffmpeg.probe(output_file, cmd='ffprobe')['format']['duration'])) - offset
        i += 1


def main():
    flv_file = sys.argv[1]
    print('Splitting {}'.format(flv_file))
    split_flv_by_size(flv_file, size=1024 * 1024 * 4000)


if __name__ == '__main__':
    main()
