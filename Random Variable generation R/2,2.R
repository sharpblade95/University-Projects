
library(rmutil)

x <- seq(-2,20,0.01)
par(mfrow=c(2,2))

xc=dlaplace(x,0,1)

xn=dnorm(x,0,1)

plot(x,xc,type="l")
lines(x,xn,col="red")

plot(x,xn/xc,type="l")
M=max(xn/xc)


nxl=M*dlaplace(x,0,1)
plot(x,nxl,type="l")
lines(x,xn,col="red")

n=1000000
ll=rlaplace(n,0,1)
u=runif(n)
g=rep(0,n)
counter=0

for ( i in 1:n)
	{
		if(ll[i]>-2){
        	if(u[i]*M*dlaplace(ll[i],0,1)<=dnorm(ll[i],0,1))
			{
	 		counter=counter+1
	 		g[counter]=ll[i]	
			}	}
	}

hist(g[1:counter],breaks= 100)

