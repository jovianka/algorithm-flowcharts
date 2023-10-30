import math

sample = [10.2, 9.7, 10.1, 10.3, 10.1, 9.8, 9.9, 10.4, 10.3, 9.8]
x = sum(sample) / 10.0 # sample mean
n = float(len(sample)) # size of the sample
h0 = 10.0 # null hypothesis mean (myu)
# h1 -> mean is not 10
slevel = 0.01
clevel = 0.99

# area from left critical area  = 1 - 0.01/2 -> 2.575 # look up table
z = 2.575

# sample standard deviation
s = 0.0
for i in sample:
    s = s + (i - x) ** 2

s = math.sqrt(s / (n - 1))

# t-value (x - myu) / (s / sqrt(n))
t = (x - h0) / (s / math.sqrt(n))

print(f"sample mean: {x}")
print(f"sample standard deviation: {s}")
print(f"z: {z}")
print(f"t: {t}")

if t > z:
    print("t > z")
    print("Reject h0 because t is in the critical area")
else:
    print ("t is not more than z")
    print("Failed to reject h0 because t is in the FTR area")

# sources
# The Organic Chemistry Tutor (God):
#   https://youtu.be/Hag0GW9B6EY
#   https://youtu.be/XHPIEp-3yC0
#   https://youtu.be/8Aw45HN5lnA
# Google up "sample standard deviation formula to find s"
# Standard Normal (Z) Table: https://www.sjsu.edu/faculty/gerstman/EpiInfo/z-table.htm

