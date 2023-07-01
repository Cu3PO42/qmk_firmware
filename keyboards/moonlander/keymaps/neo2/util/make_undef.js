#!/usr/bin/env node

const fs = require('fs');
const header = process.argv[2];
const result_file = header.substring(0, header.length - 2) + '_undef.h';

const contents = fs.readFileSync(header, 'utf-8');
const new_header = contents.replace(/#define ([a-zA-Z0-9_]+).*$/gm, '#undef $1').replace(/#(ifndef|endif|include).*/gm, '');
fs.writeFileSync(result_file, new_header, 'utf-8');
