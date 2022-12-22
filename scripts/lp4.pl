#!/usr/bin/perl

my $atomline=0;

@STORE;

open(F1,$ARGV[0])|| die("Can't open file:".$ARGV[0]);

while(<F1>)
			{
				  $atomline++  if(/^ATOM/); 
    				  next if(!/^0/);
   				  @lcontents = split(/\s+/,$_);
				  ($val) = @lcontents;
				  
				  for( $i = 0; $i < length $val; $i+=3) {
					
				   					 $sub = substr ( $val , $i, 3);
				   					 $sub =~s/^0//g;
				   					 $sub =~s/^0//g;
				   
				   					 $temp1 = $sub if($i == 0);
				   					 $temp2 = $sub if($i == 3);
				   
				   if($i == 6) {
							#print "$temp1 $temp2 $sub\n";
							$STORE[$temp1] += $sub;
							$STORE[$temp2] += $sub;
							#print "$STORE[$temp1] $STORE[$temp2]\n";
						}
									 }

			}
close(F1);
				  #print "BOND ORDER\n";
				  for( $i = 1; $i <= $atomline; $i++) {
								#print "$i  =>  $STORE[$i] \n";
								print "$STORE[$i] \n";
								}
