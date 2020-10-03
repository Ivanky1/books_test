<div id="carousel-example-generic" class="carousel slide">
    <!-- Indicators -->
    <ol class="carousel-indicators hidden-xs">
        <?php foreach(range(0, count($rows)-1) as $k) : $active = ($k == 0) ?'active' : '' ?>
            <li data-target="#carousel-example-generic" data-slide-to="<?=$k ?>" class="<?=$active ?>"></li>
        <?php endforeach; ?>

    </ol>

    <!-- Wrapper for slides -->
    <div class="carousel-inner">
        <?php foreach($rows as $k=>$row) : $active = ($k == 0) ?' active' : ''?>
            <div class="item<?=$active ?>">
                <?= preg_replace('/(img\-responsive)/', "$1 img-full", $row['field_img_slider']); ?>
            </div>
        <?php endforeach; ?>
    </div>
    <!-- Controls -->
    <a class="left carousel-control" href="#carousel-example-generic" data-slide="prev">
        <span class="icon-prev"></span>
    </a>
    <a class="right carousel-control" href="#carousel-example-generic" data-slide="next">
        <span class="icon-next"></span>
    </a>
</div>