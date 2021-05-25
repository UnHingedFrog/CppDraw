import hashlib
import timeit

crypt=input("")
#crypt="athassin"
i=1 
startTime=timeit.default_timer()
while 1:
    cryptt=crypt+str(i)
    crypts=hashlib.sha256(cryptt.encode())
    crypts=crypts.hexdigest()
    if crypts[:6] == "000000" :
        print(str(i)+"\n")
        timediff=timeit.default_timer()-startTime
        print("Time: " + str(timediff) + " seconds")
        break
    else :
        if i%1000000 == 0 :
            timediff=timeit.default_timer()-startTime
            print("Time till " + str(i) + ": " + str(timediff) + " seconds")
        i+=1
