# fuck you, $stdin of the ruby
    T=$stdin.read.to_i
		while T>0 do
			x=$stdin.read.to_i
			y=$stdin.read.to_i
			z=$stdin.read.to_i
            ytx=(1+x)*(x/2)
		    if x%2>0
			    ytx+=(x/2+1)
		    end
		    maxcus=z*x-ytx+(z-x);
			unless x<=z && maxcus>=y 
			    puts "Merry\n"
		    else
			    puts "Renko\n"
			end
			T-=1
		end
