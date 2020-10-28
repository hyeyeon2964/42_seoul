#!/bin/bash

ifconfig -a link | grep eth | sed "s/ether//" | tr -d " \t" 
