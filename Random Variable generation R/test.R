x <- seq(0,1,0.01)
par(mfrow=c(2,2))

xc=2*dcauchy(x,1/2,1)
xn= runif(1000000,0,1/2) + runif(1000000,0,1/2)
hist(xn)
plot(x,xc,type="l")


M=max(xn/xc)
print (M)
nxc=M*2*dcauchy(x,0,1)
plot(x,nxc,type="l")
lines(x,xn,col="red")

n=1000000
rr=rcauchy(n,0,1)
u=runif(n)
g=rep(0,n)
counter=0

for ( i in 1:n)
	{
		if(rr[i]>-2){
        	if(u[i]*M*2*dcauchy(rr[i],0,1)<=dnorm(rr[i],0,1))
			{
	 		counter=counter+1
	 		g[counter]=rr[i]	
			}	}
	}

hist(g[1:counter],breaks= 100)

