def getEnc(ch):
  a,b,n=3,19,26
  m=ord(i)-ord('A')
  return chr((a*m+b)%n+ord('A'))

m="THIS IS A CIPHER MESSAGE"
result=""
for i in m:
  if i==' ':
    result+=' '
  else:
    result+=getEnc(i)
print(result)