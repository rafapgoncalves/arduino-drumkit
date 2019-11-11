#!/bin/bash

#-- Constants -----------------------------------------------------------------------------------------------------------------------------------------
BASE=$(dirname "$( cd "$(dirname "$0")" ; pwd -P )")
PATTERNS=(".+\.h" ".+\.cpp");

HEADER_FILE="$BASE/license/license-header.txt"
HEADER=$(cat "$HEADER_FILE")
#------------------------------------------------------------------------------------------------------------------------------------------------------

function main() {
	crawl "$BASE"
}

function crawl() {
	for file in "$1"/*; do
		if [ -d "$file" ]; then
			crawl "$file"
		else
			checkIncludes "$file"
		fi
	done
}
function checkIncludes() {
	for pattern in "${PATTERNS[@]}"; do
		if [[ "$1" =~ ^$pattern$ ]]; then
			apply "$1"
		fi
	done
}
function apply() {
	local copywrite=0
	local start=""
	local end=""
	
	local file=$(cat "$1")
	
	if [[ "$file" =~ "Copyright" ]]; then
		copywrite=$(echo "$file" | awk '/Copyright/{print NR}' | head -n 1)
		start=$(echo "$file" | awk 'BEGIN{max=""} NR < '$copywrite' && /\/\*/ {max=NR} END{print max}')
		end=$(echo "$file" | awk 'NR > '$copywrite' && /\*\// {print NR}' | head -n 1)
	fi
	
	if [ "$start" != "" -a "$end" != "" ]; then
		file=$(removeHeader "$file" $start $end)
	fi
	file=$(addHeader "$file")
	
	echo "$file" > "$1"
}
function removeHeader() {
	echo "$1" | sed "$2,${3}d"
}
function addHeader() {
	echo "$HEADER"$'\n'"$1"
}

main "$@"
