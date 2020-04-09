# demonstrate strings, arrays and hashes

use strict;
use warnings;
use diagnostics;

use feature "say";


# strings
print("Strings\n");

my $twice_str = "This will be displayed twice. " x 2;
say($twice_str);

my $multiline_str = <<"END";
Line 1
Line 2
An example of multiline string.
END
print($multiline_str);

my $str = "Random long string";
say(qq{Length of string "$str" is: }, length($str));
say(qq{Index of "g" is: }, index($str, "g"));
say(qq{Last index of "g" is: }, rindex($str, "g"));

$str = $str . " this is the concatenated part of the string.";
say("String through index 5 to 10: ", substr($str, 5, 10));
say("Uppercase string: ", uc($str));


# arrays
print("\n\nArrays\n");

my @numbers = (0 ... 9);
say(join(", ", @numbers));

my @primes = (3, 5, 7, 11, 13, 17);
unshift(@primes, 2);
push(@primes, 19);

say("Prime numbers array");
say("Removed from index 0 to 2: ", join(", ", splice(@primes, 0, 3)));
say(join(", ", @primes));

my $test_str = "This is a test string to be split.";
my @split_test_str = split(/ /, $test_str);
for (@split_test_str) {
	say($_);
}


# hashes
print("\n\nHashes\n");

print("Enter your name: ");
my $name = <>;
chomp($name);

print("Enter your roll no: ");
my $roll_no = <> + 0;

my %student = (
	"Name" => $name,
	"Roll no" => $roll_no,
	"Subjects codes" => [
		"OSTL", 
		"OS", 
		"CG"
	],
	"Subjects name" => {
		"OSTL" => "Open Source Tech Lab",
		"OS" => "Operating System",
		"CG" => "Computer Graphics"
	}
);

while (my ($k, $v) = each(%student)) {
	say($k, " -> ", $v);
}
