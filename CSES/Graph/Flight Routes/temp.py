def getAns(no3, levels):
    ans = 1
    fs=1
    prelvlppl=1
    addedpeopleinlevel=0
    for i in range((levels)):
        currentlvlppl=prelvlppl*no3
        ans+= currentlvlppl
        prelvlppl=ans
        print(f"members added at level {i+2}: {ans:,}")
    return ans

ans=getAns(5ook, 10)
print(f"ans :{ans:,}")