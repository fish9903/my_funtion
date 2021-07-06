# test for git..

class TimeIterator:
    def __init__(self, start, stop):
        self.stop = stop
        self.start = start

    def __getitem__(self, item):
        if item < self.stop - self.start:
            hour = (self.start + item) // 3600 % 24
            min = (self.start % 3600 + item) // 60 % 60
            sec = (self.start + item) % 60
            return '{0:02d}:{1:02d}:{2:02d}'.format(hour, min, sec)
        else:
            raise StopIteration


start, stop, index = map(int, input().split())

for i in TimeIterator(start, stop):
    print(i)

print('\n', TimeIterator(start, stop)[index], sep='')