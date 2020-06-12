blih -u oscar.ayuso@epitech.eu repository create "$1"
blih -u oscar.ayuso@epitech.eu repository setacl "$1" ramassage-tek r
blih -u oscar.ayuso@epitech.eu repository getacl "$1"
git clone git@git.epitech.eu:/oscar.ayuso@epitech.eu/"$1"
