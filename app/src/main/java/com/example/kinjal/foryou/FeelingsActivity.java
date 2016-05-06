package com.example.kinjal.foryou;

import android.content.DialogInterface;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;

public class FeelingsActivity extends AppCompatActivity {

    ViewPager viewPager;
    CustomSwipeAdapter adapter;

    MediaPlayer mediaPlayer;

    int length;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_feelings);
        viewPager = (ViewPager)findViewById(R.id.viewPager);
        adapter = new CustomSwipeAdapter(this);
        viewPager.setAdapter(adapter);

        mediaPlayer = MediaPlayer.create(FeelingsActivity.this, R.raw.cuppycake);
        mediaPlayer.setLooping(true);
        mediaPlayer.setVolume(100, 100);
        mediaPlayer.start();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mediaPlayer.pause();
        length = mediaPlayer.getCurrentPosition();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mediaPlayer.seekTo(length);
        mediaPlayer.start();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        mediaPlayer.seekTo(length);
        mediaPlayer.start();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mediaPlayer.release();
    }
}
