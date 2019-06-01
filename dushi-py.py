#!/usr/bin/env python3
# usage: ./dushi.py "Hallo vrienden."
import sys
import dushi

dushi.load()  # or dushi.load("/path/to/dushi.db")
# optionally call dushi.reload("/path/to/dushi.db") to refresh database

print(dushi.bezem(sys.argv[1], smileys=5, aids=0))
