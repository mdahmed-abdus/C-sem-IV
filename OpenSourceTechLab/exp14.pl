# demonstrate loops

use strict;
use warnings;
use diagnostics;

use feature "say";


# find min and max number in array
print("Enter the number of elements: ");
my $size = <> + 0;

my @numbers;

# use of for loop
for (my $i = 0; $i < $size; $i++) {
	printf("Enter the value of element %u: ", $i);
	my $number = <> + 0;

	push(@numbers, $number);
}

my ($min, $max) = ($numbers[0], $numbers[0]);

# use of foreach
foreach my $number (@numbers) {
	if ($number < $min) {
		$min = $number;
	}
	if ($number > $max) {
		$max = $number;
	}
}

say("Smallest number is: ", $min);
say("Largest number is: ", $max);


# Armstrong number
print("Enter the number to check for Arsmtrong number: ");
my $number = <> + 0;

my $temp = $number;
my $sum = 0;

# use of while loop
while ($temp > 0) {
	my $remainder = $temp % 10;
	$sum += $remainder ** 3;
	$temp /= 10;
}

if ($sum == $number) {
	say($number, " is an Armstrong number.");
} else {
	say($number, " is not an Armstrong number.");
}


# Prime number
print("Enter the range till prime numbers are to be generated: ");
my $range = <> + 0;

say("Prime numbers are:");
my $i = 2;

# use of until loop
until ($i > $range) {
	my $flag = 1;

	for (2 ... $i / 2) {
		if ($i % $_ == 0) {
			$flag = 0;
			last;
		}
	}
	if ($flag == 1) {
		printf("%u ", $i);
	}

	$i++;
}
print("\n");


# Fibonaccci series
print("Enter the number of terms for the Fibonacci series: ");
$range = <> + 0;

say("Fibonacci series is:");
$i = 1;
my ($f, $s) = (0, 1);
my $next;

# use of do while loop
do {
	if ($i <= 1) {
		$next = $i;
	} else {
		$next = $f + $s;
		$f = $s;
		$s = $next;
	}

	printf("%u ", $next);
	$i++;
} while ($i < $range);
