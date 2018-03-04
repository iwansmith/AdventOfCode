
import md5


i = 0
while True:
  
  m = md5.new()
  m.update("bgvyzdsv{}".format(i))
  if m.hexdigest()[0:6] == "000000":
    print i
    break
  i+=1

