# Simple Line Editor in C

## Team Members

1. Shweta Masali
2. Vasundhara
3. Srushti

## Project Description

A simple command-line line editor written in C.
The editor allows users to create, view, modify and search
a small text document.

## Data Structure

A 2D character array is used to store the document.

char lines[100][200];

Each row represents one line of text.

## Implemented Features

1. Insert a line
2. Delete a line
3. Display the document
4. Search for a word or phrase

## Commands

insert <line>
delete <line>
display
search
help
quit

## Compilation

gcc main.c -o editor

## Run

.\editor