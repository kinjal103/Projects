package com.example.kinjal.foryou;

import android.content.Context;
import android.media.MediaPlayer;
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

public class SadMoments extends AppCompatActivity {

    ViewPager viewPager;
    SadSwipeAdapter adapter;

    MediaPlayer mediaPlayer;

    int length;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sad_moments);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        mediaPlayer = MediaPlayer.create(SadMoments.this, R.raw.jaane_kyun);
        mediaPlayer.setLooping(true);
        mediaPlayer.setVolume(100, 100);
        mediaPlayer.start();

        viewPager = (ViewPager)findViewById(R.id.viewPager);
        adapter = new SadSwipeAdapter(this);
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

class SadSwipeAdapter extends PagerAdapter {

    private int[] imageResource = {R.drawable.sad1, R.drawable.sad2, R.drawable.sad3, R.drawable.sad4, R.drawable.sad5, R.drawable.sad6, R.drawable.sad7, R.drawable.sad8, R.drawable.sad9, R.drawable.sad10, R.drawable.sad11, R.drawable.sad12, R.drawable.sad13, R.drawable.sad14};
    private Context ctx;
    private LayoutInflater layoutInflater;

    ImageView imageView;
    View item_view;

    public SadSwipeAdapter(Context ctx) {
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