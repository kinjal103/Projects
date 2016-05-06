package com.example.kinjal.foryou;

import android.content.Context;
import android.media.AudioManager;
import android.net.Uri;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.media.MediaPlayer;

public class MissingMe extends AppCompatActivity {

    ViewPager viewPager;
    MeSwipeAdapter adapter;

    MediaPlayer mediaPlayer;

    int length;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_missing_me);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        mediaPlayer = MediaPlayer.create(MissingMe.this, R.raw.guzaarish);
        mediaPlayer.setLooping(true);
        mediaPlayer.setVolume(100, 100);
        mediaPlayer.start();

        viewPager = (ViewPager)findViewById(R.id.viewPager);
        adapter = new MeSwipeAdapter(this);
        viewPager.setAdapter(adapter);
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

class MeSwipeAdapter extends PagerAdapter{

    private int[] imageResource = {R.drawable.me1, R.drawable.me2, R.drawable.me3, R.drawable.me4, R.drawable.me5, R.drawable.me6, R.drawable.me7, R.drawable.me8, R.drawable.me9, R.drawable.me10, R.drawable.me11, R.drawable.me12, R.drawable.me13, R.drawable.me14, R.drawable.me15, R.drawable.me16, R.drawable.me17, R.drawable.me18, R.drawable.me19, R.drawable.me20,R.drawable.me21, R.drawable.me22, R.drawable.me23, R.drawable.me24, R.drawable.me25, R.drawable.me26, R.drawable.me27, R.drawable.me28, R.drawable.me29, R.drawable.me30, R.drawable.me31, R.drawable.me32, R.drawable.me33};
    private Context ctx;
    private LayoutInflater layoutInflater;

    ImageView imageView;
    View item_view;

    public  MeSwipeAdapter(Context ctx) {
        this.ctx = ctx;
    }
    @Override
    public int getCount() {
        return imageResource.length;
    }

    @Override
    public boolean isViewFromObject(View view, Object object) {
        return (view == (LinearLayout)object);
    }

    @Override
    public Object instantiateItem(ViewGroup container, int position) {
        layoutInflater = (LayoutInflater)ctx.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        item_view = layoutInflater.inflate(R.layout.swipe_layout, container, false);
        imageView = (ImageView)item_view.findViewById(R.id.image_view);
        imageView.setImageResource(imageResource[position]);
        imageView.setId(position);
        container.addView(item_view);
        return item_view;
    }

    @Override
    public void destroyItem(ViewGroup container, int position, Object object) {
        container.removeView((LinearLayout) object);
    }
}