#!/bin/bash
# Rick Astley in your Terminal (offline, using .full + .wav)
version='1.5'

video="aca.full"
audio=""

audpid=0
fps=25          # Frames per second
frame_lines=25  # Lines per frame in the .full file

# Cleanup on exit
cleanup() { (( audpid > 1 )) && kill $audpid 2>/dev/null; }
quit() { echo -e "\x1b[2J\x1b[0H\x1b[?25h"; }
trap "cleanup" INT
trap "quit" EXIT

# Hide cursor, clear screen
echo -en "\x1b[?25l\x1b[2J\x1b[H"

# Play audio in background
if hash play 2>/dev/null; then
  play -q "$audio" &
elif hash aplay 2>/dev/null; then
  aplay -q "$audio" &
else
  echo "No audio player found (install sox or alsa-utils)." >&2
fi
audpid=$!

# Video playback
python3 <(cat <<EOF
import sys, time

fps = $fps
frame_lines = $frame_lines
time_per_frame = 1.0 / fps

# Read all lines first
with open("$video", "r", encoding="utf-8", errors="ignore") as f:
    lines = f.readlines()

total_frames = len(lines) // frame_lines
frame = 0
begin = time.time()

while frame < total_frames:
    start = frame * frame_lines
    end = start + frame_lines
    frame_buf = ''.join(lines[start:end])

    # Move cursor to top-left before printing
    sys.stdout.write("\x1b[H")
    sys.stdout.write(frame_buf)
    # Progress line
    sys.stdout.write(f"\nFrame {frame+1}/{total_frames}")
    sys.stdout.flush()

    frame += 1
    elapsed = time.time() - begin
    sleep_time = (frame * time_per_frame) - elapsed
    if sleep_time > 0:
        time.sleep(sleep_time)
EOF
)
